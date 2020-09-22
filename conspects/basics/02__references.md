## References 

### Висячие ссылки

Ссылка на объект -> закончилась область видимости

> Область видимости ссылки <= области видимости объекта!

```
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

-- подбор нужной формы функции в зависимости от аргументов.

### 
