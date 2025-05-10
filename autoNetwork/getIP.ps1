$PSDefaultParameterValues['Out-Default:NoEcho'] = $true

$scriptDirectory = $PSScriptRoot

$relativeFilePath = Join-Path -Path $scriptDirectory -ChildPath "./data/campusIP.txt"

$ipAddresses = Get-NetIPAddress -AddressFamily IPv4 | Where-Object { $_.IPAddress -match "^10.36" } | Select-Object -ExpandProperty IPAddress

# ������ BOM �� UTF-8 �������
$utf8NoBOM = New-Object System.Text.UTF8Encoding $false

[System.IO.File]::WriteAllLines($relativeFilePath, $ipAddresses, $utf8NoBOM)