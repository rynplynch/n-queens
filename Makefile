TARGET_EXEC := n-queens.sh

OBJS := main.cpp solveNQueens.cpp

CPPFLAGS := -g

# The final build step.
$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
build: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -r n-queen.sh
