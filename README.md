# entt_lib_test
test entt in a shared lib


Output for ```#define FROM_LIBRARY 0``` in ```app/main.cpp```

```
registering in app
hello
1
1
1
1
```

Output for ```#define FROM_LIBRARY 1``` in ```app/main.cpp```

```
registering: ProjectSettings
registering in library
registering: primitives
hello
0
0
0
0
```