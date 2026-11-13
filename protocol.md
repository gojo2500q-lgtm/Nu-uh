# Collaboration protocol v0

Transport: WebSocket over TLS (`wss://`). Each message is one UTF-8 JSON object.

## Client hello

```json
{"type":"hello","protocol":0,"client":"random-id","displayName":"Player","room":"ABCD12"}
```

## Room snapshot

```json
{"type":"snapshot","revision":12,"levelHash":"sha256...","operations":[]}
```

## Editor operation

```json
{"type":"op","baseRevision":12,"opId":"client:42","kind":"add","objectId":1001,"objectType":1,"x":30,"y":15,"payload":"..."}
```

Supported `kind` values are `add`, `move`, `update`, `delete`, and `cursor`. The server assigns a monotonically increasing revision and broadcasts accepted operations to the room.

## Conflict rule

The server is authoritative. Operations that target different object IDs can be applied in any order. For the same object ID, the server uses last accepted revision order. A client that falls behind requests a fresh snapshot.
