## References 

### Висячие ссылки

Ссылка на объект -> закончилась область видимости

> Область видимости ссылки <= области видимости объекта!

```c++
    int& func(int x) {  // плохо
        return x;
    }

    int& func(int& x) { // ок
        return x;
    }
```

> Ссылка подобна копированию, но без копирования

> Самурай подобен мечу, только без меча

### Крушение поезда

```c++
    GetEngine()->GetScene()->GetGraph()->GetObject(OBJ_HOUSE)->scale(10);
    ..
    GetEngine().GetScene().GetGraph().GetObject(OBJ_HOUSE).scale(10); // (со ссылками)
```

### ADL -- argument dependent lookup

--- подбор нужной формы функции в зависимости от аргументов.

```c++

    template <typename T>
    struct TypeInspector {
        std::string name() {
            return typeid(T).name();
        }              // ^^^^^^^^--------mangling
                       // RTTI -- realtime type information
    };

    template <typename T>
    std::string TypeName(T t) {
        return typeid(t).name();
    }              
                 
    ...

    char c; // -> char
    char* p; // -> char*
    char a[10]; // -> char[10]
```

### Определение размера массива 

```c++
    int data[] = {...};

    // по рабоче крестьянски
    sizeof(data) / sizeof(data[0])

    // плохой подход
    size_t size(int data[N]) {
        return sizeof(data) / sizeof(data[0])
    //                  ^______подставится размер указателя
    }

    // хороший подход
    template<int N>
    size_t size(int (&data)[N]) {
    //               ^^^^^________ссылка, потому что иначе шаблон не схватится
    //                        (массив передаётся как ссылка, и это надо писать явно)  
        return N;
    }

    // приколдес
    sizeof(char SZ(int (&data)[N]) [N])

    ....

    int g(int data[]) {
    //        ^^^^__________int* const
        size_t n = size(data); // !! CE -- защита от дурака 
    }
```

### 
