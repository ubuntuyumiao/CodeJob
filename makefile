#VPATH=include:src

CUR_DIR        =        $(shell pwd)
OBJDIR         =        $(CUR_DIR)/build
SRC            =        $(CUR_DIR)/src
INCLUDES       =        $(CUR_DIR)/include
VPATH          =        $(SRC)

# 冒号前是要生成的文件，冒号后是该文件所依赖的文件
# 下一行是生成所需的文件，注意，一定要以Tab开头

# -g：添加gdb调试选项
# -c：只编译不链接，只生成目标文件
# -o：指定生成可执行文件的名称 。 如果不使用-o选项，则会生成默认可执行文件a.out

codejob : $(OBJDIR)/code.o $(OBJDIR)/solution.o            # 依赖文件声明
	g++ -std=c++11 -g -o codejob $(OBJDIR)/code.o $(OBJDIR)/solution.o   #  将.o 文件与系统库文件链接 生成可执行程序

$(OBJDIR)/code.o : $(SRC)/code.cpp  $(INCLUDES)/solution.hpp $(INCLUDES)/interview.hpp   # 依赖文件声明       
	g++ -std=c++11 -g -c -o $(OBJDIR)/code.o $(SRC)/code.cpp	                # 生成.o 目标文件

$(OBJDIR)/solution.o : $(INCLUDES)/solution.hpp $(SRC)/solution.cpp         # 依赖文件声明
	g++ -std=c++11 -g -c -o $(OBJDIR)/solution.o  $(SRC)/solution.cpp	

	
clean :
	rm  $(OBJDIR)/code.o $(OBJDIR)/solution.o $(SRC)/codejob



