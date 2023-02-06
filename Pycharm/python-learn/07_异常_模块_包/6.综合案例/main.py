from my_utils import str_utils
from my_utils import file_utils

print(str_utils.str_reverse("Hello World!"))
print(str_utils.substr("Hello World!", 1, 3))

file_utils.print_file_info("综合案例.txt")
file_utils.append_to_file("综合案例.txt", "实验!")
file_utils.print_file_info("综合案例.txt")

