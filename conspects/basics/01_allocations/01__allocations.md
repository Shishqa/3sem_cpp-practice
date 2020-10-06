# Allocations

## C style

> malloc, calloc, free, realloc

## C++ style

> new, delete

! Нет реаллокации, т.к. есть опасность инвалидации указателей

> POD типы - типы, для которых нет ООП семантики (?)

```
    std::copy(...) вызывает memcpy для POD типов
```

### operator new

КИДАЕТ ИСКЛЮЧЕНИЕ! -- важно ловить исключение в конструкторе

```
    set_terminate - свой перехватчик
```

```

    new -> malloc -> nullptr -> 

              г--> tries to free some unnecessary memory
              |
    ---> int new_handler() -> != 0 -> malloc вызывается снова
                           -> == 0 -> exception 

         ! you can define your own new_handler()
```

STL port

![Тонкости new / delete](./01__allocations-dia.png)

#### Для закрепления написать отладочную форму new / delete / placement-new

(адрес блока, название функции, файла, линии, номер вызова) -> лог файл

```
TX_ALLOC_BREAK 
```

> Эллис, Страуструп - проглядеть

