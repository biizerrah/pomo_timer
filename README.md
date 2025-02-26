## Pomo Timer  
<img src="pomodoro-pic.png" alt="pomodoro" width="400">

[Apresentação do Projeto](https://www.youtube.com/watch?v=8kn3MeNpoag)

 
O Pomo Timer consiste no método pomodoro projetado para sistemas embarcados. O método pomodoro é amplamente conhecido e utilizado para melhorar a concentração e o foco nos estudos. No entanto, ele geralmente está disponível apenas em formato de software, vinculado a um smartphone ou a uma página web.

Essa vinculação ao mundo digital pode nos distrair facilmente. Pensando nisso, o Pomo Timer foi desenvolvido para reduzir o contato com a internet e suas distrações, oferecendo uma solução mais eficiente para manter o foco.

O Pomo Timer segue o ciclo de intervalos sugeridos pelo criador do método Francisco Cirillo.

 - 25 minutos para a realização das atividades;
 - 5 minutos para uma pausa breve;
 - 25 minutos para a realização das atividades;
 - 5 minutos para uma pausa breve;
 - 25 minutos para a realização das atividades;
 - 10 minutos para uma pausa longa;

**OBS:** Para esse projeto o tempo dos intervalos foram reduzidos.

 ### Como utilizar o Pomo Timer

**HARDWARE** 

  - Possuir uma placa de desenvolvimento raspberry pi pico;
  - Possui um display ssd1306 com essas dimensões 128 x 64;
  - 1 BUZZER;
  - 3 LEDS (verde, vermelho, azul) ou 1 LED (RGB);
  - 1 Botão;
  - Ou caso possua, apenas o kit de desenvolvimento BitDogLab contém todo o hardware mencinado acima;

**SOFTWARE**
  - Ter o Visual Studio Code instalado na sua máquina; [Download](https://code.visualstudio.com/)
 - Instale o Raspberry Pi Pico SDK: [Pico Setup Windows](https://github.com/raspberrypi/pico-setup-windows?tab=readme-ov-file). Ou sua extensão no Visual Studio Code para utilizar a biblioteca SDK
- Instalar o [CMake](https://cmake.org/download/). Para fazer o build do projeto
- O compilador GCC para ARM: [GCC ARM Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm), que fará a compilação dos códigos em C/C++
 - Tenha o Git instalado e configurado: [Git para Windows](https://git-scm.com/).

**RECOMENDAÇÕES DE USO**
- Faça o clone desse repositório
- Após o clone faça o build do projeto 
- Conecte sua placa Raspberry pi pico ou o BitDogLab em modo BOOTSEL com o computador via USB
- Compile o projeto na placa ou apenas copie e cole o arquivo de extensão UF2
- Após esses passos, apenas siga as instruções que aparecem na tela 
