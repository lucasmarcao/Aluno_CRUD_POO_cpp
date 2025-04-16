# Para realizar essa tarefa em Python, você pode usar a biblioteca zipfile, 
# que é uma forma simples e eficiente de criar arquivos ZIP. 
# Vamos supor que você tenha o script zipar.py e deseja incluir 
# todos os arquivos e pastas (inclusive o próprio zipar.py) 
# na mesma pasta dentro de um arquivo ZIP.
# Aqui está um exemplo de como você pode fazer isso:

# Passos:
# Listar os arquivos e pastas na mesma pasta do 
# script zipar.py (podemos usar os.listdir() para listar os arquivos).
# Adicionar todos os arquivos e pastas ao arquivo ZIP.
# Incluir o próprio script zipar.py no ZIP.

import os
import zipfile

# Função para zipar todos os arquivos e pastas na mesma pasta do script
def zipar_tudo():
    # Caminho do script atual (onde o arquivo zipar.py está localizado)
    caminho_atual = os.path.dirname(os.path.abspath(__file__))
    
    # Nome do arquivo zip de destino
    nome_zip = os.path.join(caminho_atual, "todos_arquivos.zip")

    # Criação do arquivo zip
    with zipfile.ZipFile(nome_zip, 'w', zipfile.ZIP_DEFLATED) as zipf:
        # Itera sobre todos os arquivos e pastas no diretório
        for root, dirs, files in os.walk(caminho_atual):
            for file in files:
                # Caminho completo do arquivo
                caminho_completo = os.path.join(root, file)
                # Caminho relativo dentro do ZIP (para manter a estrutura de pastas)
                caminho_relativo = os.path.relpath(caminho_completo, caminho_atual)
                # Adiciona o arquivo ao ZIP
                zipf.write(caminho_completo, caminho_relativo)

    print(f"Arquivo ZIP '{nome_zip}' criado com sucesso!")

# Chama a função para zipar todos os arquivos na pasta
zipar_tudo()
