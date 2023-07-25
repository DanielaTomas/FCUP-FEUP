# Clean up old runtime data
find . -name '*.gcda' -exec rm {} \;

# Run test command (specified as script arguments)
# This can be anything that runs program(s) built by the project 
"${@}"

# Generate reports (.gcov files). All .gcda files in the build directory are passed as  arguments
find . -name '*.gcda' | xargs gcov -b -c -f

