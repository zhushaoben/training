:bennettz
build > 1.in
std < 1.in > std.out
test < 1.in > test.out
fc std.out test.out
if not errorlevel 1 goto bennettz
pause