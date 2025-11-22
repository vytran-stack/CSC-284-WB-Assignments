#ifndef JSONTRANSFORMER_H
#define JSONTRANSFORMER_H

#include <string>
#include "json.hpp"

using json = nlohmann::json;

// Apply transformation rules to a JSON object.
// - Replace old email domain
// - Convert certain strings into objects
void transformJson(json& j);

#endif
