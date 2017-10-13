# EnigmaC
An enigma machine simulator in C. All configurations are generated using a psuedorandom number generator. Assuming the same number of rotors and plug boards, passing in the same seed results in the same machine configuration. 

## Usage
run `make`

run `./enigma hello` for sample encrypted message

then run `./enigma LFWBX` to see decrypt the message, where LFWBX is the result of encrypting 'hello'

`Usage: enigma {text} [--file] [--seed] [--rotors] [--plugs] [--quiet]` :
- `--file` : pass in a filename with text to encrypt/decrypt. 
- `--seed` : seed value for psuedorandom number generator. Default is 1024
- `--plugs` : number of plug connections to make. Max is 13. Defaults to 2.
- `--rotors` : number of rotors for the machine. Includes reflector i.e. `--rotors 3` has 2 rotating rotors and one reflector. Defaults to 3.
- `--quiet` : no output besides encrypted message. Useful for piping message to a file. 
