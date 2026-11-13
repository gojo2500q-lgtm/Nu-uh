#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace geode_collab {

enum class OperationType : uint8_t {
    AddObject,
    MoveObject,
    DeleteObject,
    UpdateObject,
    Cursor,
};

struct Operation {
    uint64_t revision = 0;
    std::string clientId;
    OperationType type = OperationType::Cursor;
    int objectId = 0;
    float x = 0.f;
    float y = 0.f;
    int objectType = 0;
    std::string payload;
};

class CollabSession {
public:
    void connect(std::string const& endpoint, std::string const& roomCode,
                 std::string const& clientId);
    void disconnect();
    void submit(Operation operation);
    void receive(Operation operation);

    bool isConnected() const { return m_connected; }
    std::string const& roomCode() const { return m_roomCode; }
    std::vector<Operation> const& pendingOperations() const { return m_pending; }

private:
    bool m_connected = false;
    std::string m_endpoint;
    std::string m_roomCode;
    std::string m_clientId;
    std::vector<Operation> m_pending;
};

} // namespace geode_collab
