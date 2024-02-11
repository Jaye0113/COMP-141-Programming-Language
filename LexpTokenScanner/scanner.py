import re

# 更新正则表达式以包括浮点数
# Update regular expressions to include floating point numbers
token_specification = [
    ('NUMBER',     r'\d+(\.\d*)?'),         # Integer or decimal number 整数或小数
    ('IDENTIFIER', r'[a-zA-Z_][a-zA-Z_0-9]*'), # Identifier 标识符
    ('SYMBOL',     r'[+\-*/()]'),               # Arithmetic operators 算术运算符
    ('ERROR',      r'.'),                       # Any other character 其他字符
]

# 更新 scanner 函数
# Update the scanner function
def scanner(input_string):
    tokens = []
    for mo in re.finditer('|'.join('(?P<%s>%s)' % pair for pair in token_specification), input_string.strip()):
        kind = mo.lastgroup
        value = mo.group()
        if kind == 'NUMBER' and '.' in value:
            try:
                value = float(value)  # 尝试转换为浮点数 Try converting to floating point number
            except ValueError:
                kind = 'ERROR'  # 如果转换失败，标记为错误 If conversion fails, mark as an error
        elif kind == 'NUMBER':
            value = int(value)  # 转换为整数 Convert to integer
        tokens.append((kind, value))
    return tokens

# 文件处理函数
# File processing function
def process_file(input_file_path, output_file_path):
    with open(input_file_path, 'r') as input_file, open(output_file_path, 'w') as output_file:
        line_number = 1
        first_line = True  # 添加一个标志来检查是否是第一行 Add a flag to check if it's the first line
        for line in input_file:
            # 输出当前行号和内容 Output current line number and content
            if first_line:
                output_file.write(f'Line: {line.strip()}\n')
                first_line = False
            else:
                output_file.write(f'\nLine: {line.strip()}\n')  # 在非第一行时添加一个空行 Add a blank line when it's not the first line
            tokens = scanner(line)  # 对每一行进行词法分析 Lexical analysis for each line
            for kind, value in tokens:
                if kind == 'ERROR':
                    # 如果是错误，跳过 If it's an error, skip
                    continue
                else:
                    # 否则输出标记类型和值 Otherwise output token type and value
                    output_file.write(f'{value} : {kind}\n')
            line_number += 1

if __name__ == "__main__":
    input_file_path = "test_input.txt"  # 输入文件路径 Input file path
    output_file_path = "test_output.txt"  # 输出文件路径 Output file path

    # 处理文件 Process the file
    process_file(input_file_path, output_file_path)
