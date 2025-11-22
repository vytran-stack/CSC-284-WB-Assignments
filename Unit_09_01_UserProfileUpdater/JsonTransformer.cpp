#include "JsonTransformer.h"
#include <string>
#include"json.hpp"
// Recursively walk through ALL JSON nodes (object, array, values).
void transformNode(json& node) {

    // If the node is an object, process each key/value.
    if (node.is_object()) {
        for (auto& [key, value] : node.items()) {
            transformNode(value);
        }
    }

    // If the node is an array, process each element.
    else if (node.is_array()) {
        for (auto& elem : node) {
            transformNode(elem);
        }
    }

    // If the node is a string, apply replacement rules.
    else if (node.is_string()) {
        std::string val = node.get<std::string>();

        // Rule 1: Replace email domain.
        const std::string oldDomain = "@company.com";
        const std::string newDomain = "@newcompany.com";

        if (val.size() >= oldDomain.size() &&
            val.compare(val.size() - oldDomain.size(), oldDomain.size(), oldDomain) == 0) {

            val.replace(val.size() - oldDomain.size(), oldDomain.size(), newDomain);
            node = val;
            return;
            }

        // Rule 2: Replace "enabled" with an object.
        if (val == "enabled") {
            node = json{
                    {"status", "enabled"},
                    {"since", "2024-10-01"}
            };
            return;
        }

        // Rule 3: Replace "manage_users" with an object.
        if (val == "manage_users") {
            node = json{
                    {"permission", "manage_users"},
                    {"granted_at", "2024-10-05"},
                    {"level", "full"}
            };
            return;
        }
    }
}

// Public API
void transformJson(json& j) {
    transformNode(j);
}
