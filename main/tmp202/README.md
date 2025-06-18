# Клиент-серверное приложение на Qt

## Описание
Данный проект представляет собой клиент-серверное приложение, реализованное на Qt. Приложение включает в себя следующий функционал:
- Шифрование Triple DES
- Хеширование SHA-384
- Метод хорд для решения уравнений
- Внедрение сообщений в изображения (стеганография)

## Структура проекта
- `client/` - исходный код клиентской части
- `server/` - исходный код серверной части
- `common/` - общие компоненты для клиента и сервера
- `docker/` - файлы для контейнеризации приложения

## Требования
- Qt 5.15 или выше
- C++17
- SQLite 3
- Docker Desktop (для запуска сервера)

## Сборка и запуск

### Комбинированный подход (Docker + Qt Creator) - РЕКОМЕНДУЕТСЯ
Этот подход позволяет запускать сервер в Docker, а клиентов - через Qt Creator:

1. **Запуск сервера в Docker**:
   ```powershell
   .\start_server.ps1
   ```
   Подробная инструкция в файле `docker/README.md`

2. **Запуск клиентов в Qt Creator**:
   - Откройте проект в Qt Creator
   - Выберите конфигурацию сборки для клиента
   - Запустите клиент через Qt Creator
   - Подробная инструкция в файле `client/README.md`

### Сборка и запуск вручную
1. Клонировать репозиторий
2. Открыть проект в Qt Creator
3. Собрать проект
4. Запустить сервер
5. Запустить клиент

### Сборка и запуск полностью с использованием Docker
```bash
# Сборка образа
docker-compose build

# Запуск
docker-compose up
```

## Функциональность
- Авторизация и регистрация пользователей
- Шифрование данных с использованием Triple DES
- Хеширование паролей с использованием SHA-384
- Решение уравнений методом хорд
- Стеганография: внедрение сообщений в изображения

## Архитектура
Проект использует паттерн Singleton для клиента и базы данных. Взаимодействие между компонентами описано в диаграмме UseCase. 

## Documentation

This project uses Doxygen for code documentation. To generate the documentation:

### Windows
```
generate_docs.bat
```

### Linux/macOS
```
chmod +x generate_docs.sh
./generate_docs.sh
```

After running the script, the documentation will be available in the `docs/html/` directory. Open `docs/html/index.html` in your web browser to view it.

### Installing Doxygen

- **Windows**: Download and install from [Doxygen's official website](http://www.doxygen.nl/download.html)
- **Ubuntu/Debian**: `sudo apt-get install doxygen`
- **macOS**: `brew install doxygen`

For generating graphs, you'll also need Graphviz:
- **Windows**: Download and install from [Graphviz's official website](https://graphviz.org/download/)
- **Ubuntu/Debian**: `sudo apt-get install graphviz`
- **macOS**: `brew install graphviz` 