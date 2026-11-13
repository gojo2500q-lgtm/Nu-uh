#include "CollabSession.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace geode_collab {

void CollabSession::connect(std::string const& endpoint, std::string const& roomCode,
                            std::string const& clientId) {
    m_endpoint = endpoint;
    m_roomCode = roomCode;
    m_clientId = clientId;

    // Transport is deliberately isolated from the editor model. The next step is
    // an NSURLSessionWebSocketTask adapter for iOS and a matching implementation
    // for Windows, both speaking the protocol described in protocol.md.
    log::info("Collab session requested: {} / room {}", endpoint, roomCode);
    m_connected = false;
}

void CollabSession::disconnect() {
    m_connected = false;
    m_pending.clear();
}

void CollabSession::submit(Operation operation) {
    if (!m_connected) {
        m_pending.push_back(std::move(operation));
        return;
    }
    // Transport adapter will serialize and send this operation.
}

void CollabSession::receive(Operation operation) {
    m_pending.push_back(std::move(operation));
}

} // namespace geode_collab
