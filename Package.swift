// swift-tools-version: 5.7

import PackageDescription

let package = Package(
  name: "MyWorkspaceDependencies",
  dependencies: [
    .package(path: "./MyClangLibrary")
  ]
)
