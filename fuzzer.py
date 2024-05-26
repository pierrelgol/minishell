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
    "cp -r source destination",
    "mv source destination",
    "rm -rf /path/to/directory",
    "mkdir -p /path/to/directory",
    "rmdir /path/to/directory",
    "touch filename",
    "cat filename",
    "more filename",
    "less filename",
    "head -n 10 filename",
    "tail -n 10 filename",
    "grep 'pattern' filename",
    "find /path -name filename",
    "chmod 755 filename",
    "chown user:group filename",
    "ps aux",
    "kill -9 pid",
    "top",
    "df -h",
    "du -sh /path",
    "tar -czvf archive.tar.gz /path/to/directory",
    "gzip filename",
    "gunzip filename.gz",
    "zip -r archive.zip /path/to/directory",
    "unzip archive.zip",
    "ssh user@host",
    "scp user@host:/path/to/file /local/path",
    "wget http://example.com/file",
    "curl -O http://example.com/file",
    "man command",
    "history",
    "alias ll='ls -l'",
    "nano filename",
    "vim filename",
    "awk '/pattern/ {print $0}' filename",
    "sed 's/foo/bar/g' filename",
    "sort filename",
    "uniq filename",
    "diff file1 file2",
    "export VAR=value",
    "env",
    "source filename",
    "which command",
    "basename /path/to/file",
    "dirname /path/to/file",
    "xargs command"
]

pipes = ["|"]
redirections = [">", ">>", "<", "<<"]
incorrect_elements = ["-l cat", ">>>", "| |", ">> >>", "<>"]

def generate_correct_command_chain():
    num_commands = random.randint(1, 8)
    command_chain = []

    for i in range(num_commands):
        command_chain.append(random.choice(commands))
        if i < num_commands - 1:
            command_chain.append(random.choice(pipes + redirections))

    return " ".join(command_chain)

def generate_incorrect_command_chain():
    num_commands = random.randint(1, 8)
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
