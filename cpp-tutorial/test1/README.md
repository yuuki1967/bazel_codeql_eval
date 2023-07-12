# Test 1

In this stage we step it up and showcase how to integrate multiple ```cc_library``` targets from different packages.

Below, we see a similar configuration from Stage 2, except that this BUILD file is in a subdirectory called lib. In Bazel, subdirectories containing BUILD files are known as packages. The new property ```visibility``` will tell Bazel which package(s) can reference this target, in this case the ```//main``` package can use ```hello-time``` library. 

```
cc_library(
)
```

To use our ```hello-time``` library, an extra dependency is added in the form of //path/to/package:target_name, in this case, it's ```//lib:hello-time```

```
cc_binary(
)
```

To build this example, use
```
bazel build //main:test
```

