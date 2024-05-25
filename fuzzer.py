import random
import subprocess
import sys

# A list of some common shell commands and options for generating command chains.
commands = [
    "echo 'Hello World'",
    "ls -l",
    "ls -l | grep \"myfile\" > output.txt",
    "sort",
    "wc -l",
    "head -n 10",
    "tail -n 10",
    "tr 'a-z' 'A-Z'",
    "sed 's/foo/bar/g'"
]

pipes = ["|"]
redirections = [">", ">>", "<", "<<"]
incorrect_elements = ["-l cat", ">>>", "| |", ">> >>", "<>"]

def generate_correct_command_chain():
    num_commands = random.randint(1, 10)
    command_chain = []

    for i in range(num_commands):
        command_chain.append(random.choice(commands))
        if i < num_commands - 1:
            command_chain.append(random.choice(pipes + redirections))

    return " ".join(command_chain)

def generate_incorrect_command_chain():
    num_commands = random.randint(2, 5)
    command_chain = []

    for i in range(num_commands):
        if random.random() < 0.3:  # 30% chance to insert an incorrect element
            command_chain.append(random.choice(incorrect_elements))
        else:
            command_chain.append(random.choice(commands))
        if i < num_commands - 1:
            command_chain.append(random.choice(pipes + redirections))

    return " ".join(command_chain)

def main():
    if len(sys.argv) > 1 and sys.argv[1] == '-i':
        # Generate an incorrect command chain
        command_chain = generate_incorrect_command_chain()
    else:
        # Generate a correct command chain
        command_chain = generate_correct_command_chain()

    print(command_chain)

if __name__ == "__main__":
    main()

