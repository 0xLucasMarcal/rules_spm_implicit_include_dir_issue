# Issue: rules_swift_package_manager doesn't add include dir to the publicHeadersPath implicitly


# Steps to reproduce the issue

Run the following commands:

```
bazel build //MyApp:MyApp
```

You will see the following error:

```
external/rules_swift_package_manager++swift_deps+swiftpkg_myclanglibrary/lib/src/lib.c:3:10: fatal error: 'MyClangLibrary/API.h' file not found
    3 | #include "MyClangLibrary/API.h"
      |          ^~~~~~~~~~~~~~~~~~~~~~
1 error generated.
```

This is because the include directory is not added to the publicHeadersPath implicitly.

When building with native Swift Package Manager, the include directory is added to the publicHeadersPath implicitly and the build succeeds.

```
$ cd MyClangLibrary
$ swift build

Building for debugging...
Build complete! (0.02s)
```

# Explicitly adding the include dir to the publicHeadersPath:

Open the `Package.swift` file and add the following line to the `MyClangLibrary` target:

```
publicHeadersPath: "include"
```

Then run the following command:

```
bazel clean --expunge && bazel build //MyApp:MyApp
# The bazel clean --expunge is necessary because the rules_swift_package_manager doesn't detect the changes to local packages
```

The build will succeed.

# Conclusion

The rules_swift_package_manager doesn't add the include dir to the publicHeadersPath implicitly.

The workaround is to explicitly add the include dir to the publicHeadersPath in the `Package.swift` file.

# Solution

https://github.com/cgrindel/rules_swift_package_manager/pull/1429

The solution is to add the include dir, if it exists, to the `public_includes` list of `clang_scr_info` even when `publicHeadersPath` is not set.

This is the correct behavior according to the Apple docs:
https://developer.apple.com/documentation/packagedescription/target/publicheaderspath

To test the solution, you can use the following git_override:

(Remember to remove the publicHeadersPath from the `Package.swift` file before running the build)

```
bazel_dep(name = "rules_swift_package_manager", version = "0.43.0")
git_override(
    module_name = "rules_swift_package_manager",
    remote = "https://github.com/0xLucasMarcal/rules_swift_package_manager.git",
    commit = "a20242c944fb899fdb037027080f33651c18b487",
)
```

and run the following command:

```
bazel build //MyApp:MyApp
```

The build will succeed.



