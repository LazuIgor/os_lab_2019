#!/bin/bash

# Проверка, что переданы аргументы
if [ $# -eq 0 ]; then
  echo "Error: You must enter at least one argument."
  exit 1
fi

# Объявление переменных
sum=0
count=0

# Цикл для обработки всех входных аргументов
for arg in "$@"; do

    # Количество аргументов увеличено на 1
    ((count++))

    # Сумма аргументов увеличена на аргумент запускаемого файла: аргументы Bash исполняются
    ((sum += $arg))

done

# Окончательные числа и среднее арифметическое выводятся мониторы
echo "Number of arguments: $count"
echo "Arithmetic mean: $(echo "scale = 2; $sum / $count" | bc -l)"