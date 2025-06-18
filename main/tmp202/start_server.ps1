# PowerShell скрипт для запуска сервера в Docker

# Включаем BuildKit для ускорения сборки
$env:DOCKER_BUILDKIT = 1
$env:COMPOSE_DOCKER_CLI_BUILD = 1

# Создаем директорию для данных сервера, если её нет
if (!(Test-Path -Path ".\server_data")) {
    New-Item -ItemType Directory -Path ".\server_data" | Out-Null
    Write-Host "Создана директория server_data для данных сервера" -ForegroundColor Green
}

# Сборка образа Docker с использованием кэша
Write-Host "Сборка Docker образа (оптимизированная)..." -ForegroundColor Cyan
docker-compose build --parallel

# Запуск Docker контейнера с сервером
Write-Host "Запуск сервера в Docker..." -ForegroundColor Cyan
docker-compose up -d

Write-Host "`nСервер запущен на порту 12345" -ForegroundColor Green
Write-Host "Для остановки сервера выполните: docker-compose down" -ForegroundColor Yellow 