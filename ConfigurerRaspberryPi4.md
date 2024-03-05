# Configuration de son Raspberry Pi

Voici la configuration nécessaire pour son Raspberry Pi 4 dans le cadre du cours 420-253-MT Objets connectés

> Le système d'exploitation utilisé est Raspberry Pi OS 32-bit avec bureau. N'hésitez pas à utiliser [Raspberry Pi Imager](https://www.raspberrypi.org/software/) pour formater votre carte micro SD.

## Configuration de base

À venir.

## Logiciels

### Git

Installation :

```sh
sudo apt update
sudo apt install git
```

Valider l'installation :

```sh
git --version
```

Configuration initiale :

> N'oubliez pas de changer les valeurs par défaut.

```sh
git config --global user.name "john doe"
git config --global user.email "johndoe@mail.com"
```

Valider la configuration initiale :

```sh
git config --list
```

### Visual Studio Code

Installer Visual Studio Code :

```sh
# Installer curl
sudo apt install curl -y

# Installer le repository et la clé manuellement
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg	
sudo install -o root -g root -m 644 packages.microsoft.gpg /usr/share/keyrings/

wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'

# Mise à jour de la cache du package et installation
sudo apt-get install apt-transport-https
sudo apt-get update
sudo apt-get install code
```

#### Extensions

```sh
code --install-extension bmewburn.vscode-intelephense-client
code --install-extension DavidAnson.vscode-markdownlint
code --install-extension donjayamanne.githistory
code --install-extension eamodio.gitlens
code --install-extension EditorConfig.EditorConfig
code --install-extension ms-python.python
code --install-extension ms-vscode.vs-keybindings
code --install-extension vscode-icons-team.vscode-icons
code --install-extension yzane.markdown-pdf
code --install-extension PhonicCanine.micro-bit
```

Ajouter la police Cascadia Code PL :

```sh
# Documentations :
# - https://linuxconfig.org/how-to-install-fonts-on-ubuntu-18-04-bionic-beaver-linux
# - https://linoxide.com/linux-how-to/install-fonts-on-ubuntu/

# Prérequis
sudo apt install unzip
sudo apt-get install fontconfig -y

# Téléchargement du fichier ZIP qui contient le TTF dans le répertoire "Downloads"
wget -c https://github.com/microsoft/cascadia-code/releases/download/v2009.22/CascadiaCode-2009.22.zip -O ~/Downloads/CascadiaCode.zip

# Dézipper le ZIP
unzip -q ~/Downloads/CascadiaCode.zip

# Créer le répertoire pour contenir les polices si celui-ci n'existe pas
mkdir -p ~/.local/share/fonts

# Déplacer le fichier ttf dans le répertoire des polices
mv ~/Downloads/ttf/CascadiaCodePL.ttf  ~/.local/share/fonts

# Vider et régénérer la cache de la police
fc-cache -f -v
```

> Dans le cas où vous avez un problème lors de la commande "mkdir -p ~/.local/share/fonts", exécutez la commande "unzip -q ~/Downloads/CascadiaCode.zip" de nouveau.

Configuration à mettre dans le fichier settings.json :

```json
{
    "editor.tabCompletion": "on",
    "editor.suggestSelection": "first",
    "editor.rulers": [80,120],
    "editor.fontSize": 18,
    "editor.quickSuggestions": {
        "other": true,
        "comments": false,
        "strings": false
    },
    "editor.fontLigatures": true,
    "editor.fontFamily": "'Cascadia Code PL'",
    "emmet.showAbbreviationSuggestions": true,
    "editor.renderIndentGuides": false,
    "[markdown]": {

        "editor.wordWrap": "on",
        "editor.quickSuggestions": false
    },
    "terminal.integrated.fontFamily": "'Cascadia Code PL'",
    "workbench.iconTheme": "vscode-icons",
    "editor.wordWrap": "on"
}
```

### Python

Python devrait être installé par défaut, il est possible de vérifier s'il est présent en utilisant la commande :

Installation :

```sh
sudo apt update
sudo apt install python3 python3-pip idle3
```

Vérifier l'installation :

```sh
python3 --version
```

### Éditeur Mu

Installation :

```sh
sudo apt update
sudo apt-get install mu-editor
```
