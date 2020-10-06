## Способ определения кнопки

1. Виртуальная функция в абстрактном классе 

2. Функтор как поле кнопки

3. Variadic Templates


```c++
new Button(target, Signal(args));

struct MySignal : public Signal {
    

}


Button {

    const Signal& signal;

    Object* target;
}
```
