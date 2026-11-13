# Build without owning a Mac

You can compile the iOS `.geode` package using GitHub Actions. GitHub supplies a temporary hosted macOS runner with Xcode, so no local Mac is required.

1. Create a GitHub repository.
2. Upload this project, including `.github/workflows/build-ios.yml`.
3. Open the repository's **Actions** tab.
4. Select **Build Geode Collab for iOS** and choose **Run workflow**. A push to the `main` branch also starts it automatically.
5. When the run finishes, open the run's **Artifacts** section and download `geode-collab-ios`.
6. Install the resulting `.geode` file through a supported iOS Geode Launcher workflow.

The workflow uses the official `geode-sdk/build-geode-mod` action on `macos-latest` and requests the `iOS` target. GitHub may require a verified account or billing setup for Actions, depending on the account and repository. Public repositories generally have the most straightforward access to hosted runner minutes.
