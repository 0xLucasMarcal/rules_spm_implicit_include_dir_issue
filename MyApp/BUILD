load("@build_bazel_rules_apple//apple:macos.bzl", "macos_command_line_application")
load("@build_bazel_rules_swift//swift:swift.bzl", "swift_library")

macos_command_line_application(
    name = "MyApp",
    minimum_os_version = "14.0",
    deps = [
        ":MyAppLib",
    ],
    visibility = ["//visibility:public"],
)

swift_library(
    name = "MyAppLib",
    srcs = glob(["main.swift"]),
    deps = [
        "@swiftpkg_myclanglibrary//:MyClangLibrary",
    ],
)