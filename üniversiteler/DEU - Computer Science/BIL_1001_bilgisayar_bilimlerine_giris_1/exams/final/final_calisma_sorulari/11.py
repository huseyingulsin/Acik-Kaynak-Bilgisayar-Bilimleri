pos1 = raw_input().split()

print("ayni" if ord(pos1[0]) + ord(pos1[2]) == ord(pos2[0]) + ord(pos2[2]) else "farkli")
