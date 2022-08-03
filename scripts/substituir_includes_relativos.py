from os.path import exists,abspath

MAIN_INO_PATH = "build/main/main.ino"

if exists(MAIN_INO_PATH):
    with open(MAIN_INO_PATH, 'r+') as main_ino:
        text = main_ino.read()
        text = text.split("\n")
        for idx,line in enumerate(text):
            if '#include "src/include/' in line and (line[0] + line[1]) != '//':
                relative_path = line.split(" ")[1].replace('"','')
                relative_path = "src/main/" + relative_path
                full_path = abspath(relative_path)
                text[idx] = '#include "{}"'.format(full_path)

        full_text = "\n".join(text)

        main_ino.seek(0)
        main_ino.write(full_text)
        main_ino.truncate()


        print()
        print()
        print("-------------------- ATENÇÃO ------------------")
        print("Includes relativos foram substituídos com caminhos absolutos no arquivo main.ino.\n"
                + "Abra o arquivo build/main/main.ino na IDE para realizar o envio.\n"
                + "Perceba que a pasta build não é a mesma de src, que é\n"
                + "onde está o código original. A pasta build foi criada apenas\n"
                + "para compilar e enviar o código.\n"
                + "Após qualquer alteração no código em src, execute\n"
                + "`make prepare` novamente.\n\n"
                + "PS.: para abrir o arquivo execute `open build/main/main.ino` no mac e\n"
                + "`xdg-open build/main/main.ino` no linux.")
        print("\n\nTUDO OK!!!")
else:
    print("main.ino não encontrado.")
