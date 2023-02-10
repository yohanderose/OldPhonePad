# Old Phone Pad

Extensible module that converts old brick phone key presses to readable words.

-   Tokenises input and translates tokens efficiently (O(n))
-   Abstract and modular architecture making _NewPhonePad_ possible
-   Test coverage

## Dependencies :package:

-   C++
-   Make

## Install & Run :traffic_light:

1. Clone, cd inside and

```sh
make demo
# 4433555 555666# --> HELLO
# 8 88777444666*664# --> TURING

```

For manual input

```sh
make run < your_input.txt
```

## Test :wrench:

```sh
make tests
```
