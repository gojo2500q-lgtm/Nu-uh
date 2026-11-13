#include <Geode/Geode.hpp>
#include "CollabSession.hpp"

using namespace geode::prelude;
using namespace geode_collab;

$on_mod(Loaded) {
    log::info("Geode Collab loaded for the editor collaboration prototype");
    log::info("Target: Geometry Dash 2.208 / iOS first");
    log::info("UI and WebSocket transport are the next implementation layer");
    geode::Mod::get()->setSavedValue("prototype-loaded", true);
}
