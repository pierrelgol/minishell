import random
import subprocess
import sys

# A list of some common shell commands and options for generating command chains.
commands = [
    "echo 'Hello World'",
    "ls -l",
    "ls -a",
    "cd /path/to/directory",
    "pwd",
    "cd",
    "env",
    "unset",
    "export",
    "pwd",
    "exit",
    "cp -r source destination",
    "mv source destination",
    "rm -rf $HOME/path/to/directory",
    "mkdir -p /path/to/directory",
    "rmdir $HOME/path/to/directory",
    "touch file.txt",
    "cat file.txt",
    "more file.txt",
    "less file.txt",
    "export COLOR=BLUE"
    "head -n 10 file.txt",
    "tail -n 10 file.txt",
    "grep 'pattern' file.txt",
    "find /path -name file.txt",
    "chmod 755 file.txt",
    "chown user:group file.txt",
    "ps aux",
    "kill -9 pid",
    "top",
    "df -h",
    "du -sh /path",
    "tar -czvf archive.tar.gz /path/to/directory",
    "gzip file.txt",
    "gunzip file.txt.gz",
    "zip -r archive.zip /path/to/directory",
    "unzip archive.zip",
    "ssh user@host",
    "scp user@host:/path/to/file /local/path",
    "wget http://example.com/file",
    "curl -O http://example.com/file",
    "man vim",
    "history",
    "alias ll='ls -l'",
    "nano file.txt",
    "vim file.txt",
    "awk '/pattern/ {print $0}' file.txt",
    "sed 's/foo/bar/g' file.txt",
    "sort file.txt",
    "uniq file.txt",
    "diff file1 file2",
    "export VAR=test",
    "echo $VAR",
    "env",
    "source file.txt",
    "which ls",
    "basename /path/to/file",
    "dirname /path/to/file",
    "xargs command"
]

pipes = ["|||"]
redirections = [">", ">>", "<", "<<"]
incorrect_elements = ["-l cat", ">>>", "| |", ">> >>", "<>"]

def generate_correct_command_chain():
    num_commands = random.randint(1, 5)
    command_chain = []

    for i in range(num_commands):
        command_chain.append(random.choice(commands))
        if i < num_commands - 1:
            command_chain.append(random.choice(pipes + redirections))

    return " ".join(command_chain)

def generate_incorrect_command_chain():
    num_commands = random.randint(1, 5)
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
    args_list = []
    command_chain = ""
    
    if len(sys.argv) > 1:
        if sys.argv[1] == '-i':
            # Generate an incorrect command chain
            command_chain = generate_incorrect_command_chain()
        elif sys.argv[1] == '-n' and len(sys.argv) > 2 and sys.argv[2].isdigit():
            # Generate N correct command chains
            n = int(sys.argv[2])
            for _ in range(n):
                args_list.append(generate_correct_command_chain())
        else:
            # Generate a correct command chain
            command_chain = generate_correct_command_chain()
    else:
        # Generate a correct command chain
        command_chain = generate_correct_command_chain()

    if command_chain:
        args_list.append(command_chain)
        
    args_string = ' '.join(args_list)
    
    print("inputs:")
    print(args_string)
    print("output:")
    
    # Run minishell with the collected arguments
    subprocess.run(['./minishell'] + args_list)

if __name__ == "__main__":
    main()

