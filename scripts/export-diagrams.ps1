$Root = Split-Path $PSScriptRoot -Parent

$PlantUML = Join-Path $Root "tools\plantuml.jar"
$InputDir = Join-Path $Root "docs\UML\diagrams"
$OutputDir = Join-Path $Root "docs\UML\generated"

Write-Host "LNDH UML Generator"
Write-Host "------------------"
Write-Host "Root: $Root"
Write-Host "PlantUML: $PlantUML"
Write-Host "Input: $InputDir"
Write-Host "Output: $OutputDir"

New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null

Get-ChildItem $InputDir -Filter *.puml | ForEach-Object {

    Write-Host "Generating $($_.Name)..."

    java -jar $PlantUML `
        -tsvg `
        -o $OutputDir `
        $_.FullName
}

Write-Host "------------------"
Write-Host "UML generation complete."