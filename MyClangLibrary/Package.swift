// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MyClangLibrary",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "MyClangLibrary",
            targets: ["MyClangLibrary"]),
    ],
    targets: [
        .target(
            name: "MyClangLibrary",
            path: "lib",
            sources: ["src"]
            //publicHeadersPath: "include"
        )
    ],
    cLanguageStandard: .c11
)