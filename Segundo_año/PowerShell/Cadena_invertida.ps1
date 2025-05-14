#Mostrar cadena invertida

$num_a= 1234
[int]$digit
while($num_a -gt 0){
    $digit=$num_a % 10
    Write-Output $digit
    $num_a=[int]($num_a /10)

}