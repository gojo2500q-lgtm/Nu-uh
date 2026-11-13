# Geode Collab — iOS-first prototype

This is the starting Geode project for a public, real-time Geometry Dash editor collaboration mod targeting **Geometry Dash 2.208** and **iOS first**.

## Current status

The project currently contains the iOS-aware Geode build configuration, mod metadata, and a platform-neutral operation/session model. It is intentionally not presented as a finished multiplayer mod yet: the editor hooks, iOS WebSocket transport, public-room UI, conflict handling, and level serialization still need to be implemented and tested against the exact 2.208 iOS binary.

The intended first milestone is a two-person public room where collaborators can add, move, update, and delete editor objects. Operations will be sent as small changes rather than repeatedly sending the complete level.

## Build requirements

Geode's official iOS documentation requires macOS with Xcode and the iPhone SDK. Install iOS Geode binaries and build with:

```sh
geode sdk install-binaries --platform ios
geode build -p ios
```

The resulting `.geode` package must be installed through a supported iOS Geode launcher workflow. The sandbox used to prepare this source is Linux, so it cannot produce or sign the final iOS binary.

If you do not own a Mac, the included `.github/workflows/build-ios.yml` can compile the mod on GitHub's hosted macOS runner. See [BUILD_WITHOUT_MAC.md](BUILD_WITHOUT_MAC.md) for the upload and artifact-download steps.

## Planned next implementation steps

1. Hook the 2.208 editor object mutation paths and assign stable per-session object IDs.
2. Add an iOS `NSURLSessionWebSocketTask` transport adapter and reconnect/queue logic.
3. Add a public-room browser with room creation, join, leave, and host permissions.
4. Apply remote operations on the main thread and render collaborator cursors.
5. Add a small authoritative relay server with room expiry and rate limits.
6. Test on a sideloaded iOS 2.208 installation before adding Windows parity.

## Important safety boundary

The server should transmit editor operations only. It should not modify Geometry Dash's official online services or automate uploads to them.
