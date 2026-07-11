## PowerShell Execution Policy (Windows)

Kung gagamit ng ibang development machine, siguraduhing maitakda ang PowerShell execution policy upang payagan ang lokal na automation scripts ng proyekto.

Patakbuhin sa PowerShell:

```powershell
Set-ExecutionPolicy -Scope CurrentUser RemoteSigned
```

I-verify ang setting:

```powershell
Get-ExecutionPolicy -List
```

Dapat makita ang:

```text
CurrentUser    RemoteSigned
```

Kailangan ito upang mapatakbo ang mga project script tulad ng:

```powershell
.\scripts\export-diagrams.ps1
```

Ang setting na ito ay naka-save para sa user account at hindi na kailangang ulitin sa bawat pagbukas ng terminal.
