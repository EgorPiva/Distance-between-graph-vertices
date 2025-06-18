$base64 = "iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVR42mP8z8BQDwAEhQGAhKmMIQAAAABJRU5ErkJggg=="
$iconPaths = @(
    "client/icons/app_icon.png",
    "client/icons/encrypt.png",
    "client/icons/decrypt.png",
    "client/icons/math.png",
    "client/icons/stegano.png"
)

foreach ($path in $iconPaths) {
    [System.Convert]::FromBase64String($base64) | Set-Content -Path $path -Encoding Byte
    Write-Host "Created $path"
} 