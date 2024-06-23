# EmeraldsLinkedList

A linked list implementation using the pointer to pointer method.

# Installation

- Install the library

`em list`
`em install`
`em build lib`

## Usage

- Include in a file

`touch test.c`

```c
#include "EmeraldsLinkedList.h"

int main(void) {
  /* Create a new linked list object */
  EmeraldsLinkedList *l = linked_list_new();

  /* Add a void* value into the list */
  linked_list_add(l, (void*)1);
  linked_list_add(l, (void*)2);

  int v1 = linked_list_get(l, 0);
  printf("%d\n", v1);
}
```

- Compile

`clang test.c export/*.o $(find ./libs -name "*.*o" | xargs ls -d)`

## Development

- Delete memory when removing an element
- Write tests

## Contributing

1. Fork it (<https://github.com/The-Fourth-Wall/EmeraldsLinkedList/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
