$Root = Split-Path $PSScriptRoot -Parent

$PlantUML = Join-Path $Root "tools\plantuml.jar"
$InputDir = Join-Path $Root "docs\UML\diagrams"
$OutputDir = Join-Path $Root "docs\UML\generated"

Write-Host "+-------------------------------------------------------+"
Write-Host "|            TAGAPAGLUWAS NG MGA DAYAGRAM               |"
Write-Host "+-------------------------------------------------------+"
# Write-Host "Puno        : $Root"
# Write-Host "PlantUML    : $PlantUML"
# Write-Host "Ipapasok    : $InputDir"
# Write-Host "Ilalabas    : $OutputDir"
# Write-Host " "

New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null

Get-ChildItem $InputDir -Filter *.puml | ForEach-Object {

    Write-Host "    Nililikha ang $($_.Name)..."

    java -jar $PlantUML `
        -tsvg `
        -o $OutputDir `
        $_.FullName
}

Write-Host "+-------------------------------------------------------+"
Write-Host "|        Natapos ang pagluwas ng mga dayagram!          |"
Write-Host "+-------------------------------------------------------+"