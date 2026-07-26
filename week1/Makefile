#第一版Makefile  .PHONY 为显式声明伟目标，防止目录恰好命名为 all /clean 引发异常
# 	执行顺序：
# 		1.构建all
# 		2.all的依赖 build_Makefile 需要先处理
# 		3.执行 build_Makefile 规则 mkdir -p build_Makefile
# 		4.执行 all 下所有 g++ 编译命令
# 	因为目标名和文件夹同名，只要往文件夹里写入文件、修改文件夹时间戳，后续每次 make 都会认为 build_Makefile “被更新了”，于是会重新执行 all 下面全部 g++ 命令，无法增量编译，每次全部重编。
# OUT_DIR := build_Makefile

# all: $(OUT_DIR)
# 	g++ ./day1/pointer_ref_test.cpp -o $(OUT_DIR)/pointer_ref_test -std=c++17
# 	g++ ./day2/virtual_test.cpp -o $(OUT_DIR)/virtual_test -std=c++17
# 	g++ ./day3/smart_ptr_demo.cpp -o $(OUT_DIR)/smart_ptr_demo -std=c++17
# 	g++ ./day4/tensor.cpp -o $(OUT_DIR)/tensor -std=c++17
# 	g++ ./day6/atomic_demo.cpp -o $(OUT_DIR)/atomic_demo -std=c++17 -pthread
# 	g++ ./day6/condition_variable.cpp -o $(OUT_DIR)/condition_variable -std=c++17 -pthread

# # 创建文件夹规则
# $(OUT_DIR):
# 	mkdir -p $@

# clean:
# 	rm -rf $(OUT_DIR)
# .PHONY: all clean














# 第二版Makefile build_Makefile 改为顺序依赖 但还是做不到增量编译,因为磁盘上没有all这个文件，每次都要重新构建
# OUT_DIR := build_Makefile

# all: | $(OUT_DIR)
# 	g++ ./day1/pointer_ref_test.cpp -o $(OUT_DIR)/pointer_ref_test -std=c++17
# 	g++ ./day2/virtual_test.cpp -o $(OUT_DIR)/virtual_test -std=c++17
# 	g++ ./day3/smart_ptr_demo.cpp -o $(OUT_DIR)/smart_ptr_demo -std=c++17
# 	g++ ./day4/tensor.cpp -o $(OUT_DIR)/tensor -std=c++17
# 	g++ ./day6/atomic_demo.cpp -o $(OUT_DIR)/atomic_demo -std=c++17 -pthread
# 	g++ ./day6/condition_variable.cpp -o $(OUT_DIR)/condition_variable -std=c++17 -pthread

# # 创建文件夹规则
# $(OUT_DIR):
# 	mkdir -p $@

# clean:
# 	rm -rf $(OUT_DIR)
# .PHONY: all clean











# 第三版Makefile  支持增量编译 + 自动创建目录 + 规避文件夹时间戳坑
OUT_DIR := build_Makefile
OBJ_DIR := $(OUT_DIR)/obj
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g
THREAD_FLAGS := -pthread

TARGETS := \
$(OUT_DIR)/pointer_ref_test \
$(OUT_DIR)/virtual_test \
$(OUT_DIR)/smart_ptr_demo \
$(OUT_DIR)/tensor \
$(OUT_DIR)/atomic_demo \
$(OUT_DIR)/condition_variable

all: $(TARGETS)

#链接
$(OUT_DIR)/pointer_ref_test : $(OBJ_DIR)/pointer_ref_test.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS)
$(OUT_DIR)/virtual_test : $(OBJ_DIR)/virtual_test.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS)
$(OUT_DIR)/smart_ptr_demo : $(OBJ_DIR)/smart_ptr_demo.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS)
$(OUT_DIR)/tensor : $(OBJ_DIR)/tensor.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS)
$(OUT_DIR)/atomic_demo : $(OBJ_DIR)/atomic_demo.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS) $(THREAD_FLAGS)
$(OUT_DIR)/condition_variable : $(OBJ_DIR)/condition_variable.o | $(OUT_DIR)
	$(CXX) $< -o $@ $(CXXFLAGS) $(THREAD_FLAGS)


#编译
$(OBJ_DIR)/pointer_ref_test.o : ./day1/pointer_ref_test.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)
$(OBJ_DIR)/virtual_test.o : ./day2/virtual_test.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)
$(OBJ_DIR)/smart_ptr_demo.o : ./day3/smart_ptr_demo.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)
$(OBJ_DIR)/tensor.o : ./day4/tensor.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)
$(OBJ_DIR)/atomic_demo.o : ./day6/atomic_demo.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) 
$(OBJ_DIR)/condition_variable.o : ./day6/condition_variable.cpp | $(OBJ_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS) 


$(OUT_DIR):
	mkdir -p $@
$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean