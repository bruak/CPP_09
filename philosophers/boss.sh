#!/bin/bash

# Bulunduğumuz dizinde ve alt dizinlerdeki tüm .Identifier dosyalarını sil
find . -type f -name '*.Identifier' -exec rm -f {} \;
echo "Tüm .Identifier ve .o dosyalari silindi."