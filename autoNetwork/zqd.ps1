$exeName = "autoNetwork.exe"  # 请替换为实际exe文件名
$exePath = Join-Path $PSScriptRoot $exeName
$regPath = "HKCU:\Software\Microsoft\Windows\CurrentVersion\Run"  # 当前用户自启动（无需管理员）
# 如需所有用户自启动（需管理员权限），改为："HKLM:\Software\Microsoft\Windows\CurrentVersion\Run"

Set-ItemProperty -Path $regPath -Name "AutoRun_$exeName" -Value $exePath -Type String