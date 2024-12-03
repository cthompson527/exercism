const std = @import("std");
const mem = std.mem;

/// Encodes `s` using the Atbash cipher. Caller owns the returned memory.
pub fn encode(allocator: mem.Allocator, s: []const u8) mem.Allocator.Error![]u8 {
    var ptr = std.ArrayList(u8).init(allocator);
    var count: u8 = 0;
    for (s) |value| {
        switch (value) {
            'a'...'z' => {
                try ptr.append((26 - (value - 'a' + 1)) + 'a');
                count += 1;
            },
            'A'...'Z' => {
                try ptr.append((26 - (value - 'A' + 1)) + 'a');
                count += 1;
            },
            '0'...'9' => {
                try ptr.append(value);
                count += 1;
            },
            else => {},
        }
        if (count == 5) {
            try ptr.append(' ');
            count = 0;
        }
    }
    if (ptr.getLast() == ' ') {
        _ = ptr.pop();
    }
    return ptr.toOwnedSlice();
}

/// Decodes `s` using the Atbash cipher. Caller owns the returned memory.
pub fn decode(allocator: mem.Allocator, s: []const u8) mem.Allocator.Error![]u8 {
    var ptr = std.ArrayList(u8).init(allocator);
    for (s) |value| {
        switch (value) {
            'a'...'z' => {
                try ptr.append((26 - (value - 'a' + 1)) + 'a');
            },
            '0'...'9' => {
                try ptr.append(value);
            },
            else => {},
        }
    }
    return ptr.toOwnedSlice();
}
