if __name__ == "__main__":

    with open('shakespeare.txt', 'r+b') as f:
        f.seek(0)
        content = f.read()
        for i in range(300):
            f.write(content)