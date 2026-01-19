import sys
import subprocess

def run_srec_cat(input_file, output_file):
    cmd = ["srec_cat", input_file, "-Intel", "-o", output_file, "-Binary"]
    try:
        subprocess.run(cmd, check=True)
        print(f"Successfully created {output_file} from {input_file}")
    except subprocess.CalledProcessError as e:
        print(f"Error running srec_cat: {e}")
        sys.exit(2)

def trim_zeros(input_file, output_file):
    with open(input_file, "rb") as f:
        data = f.read()
    trimmed_data = data.lstrip(b"\x00")
    with open(output_file, "wb") as f:
        f.write(trimmed_data)
    print(f"Zeros trimmed. Output written to {output_file}")

def split_file_on_magic(input_file, split_hex):
    split_bytes = bytes.fromhex(split_hex)
    with open(input_file, "rb") as f:
        data = f.read()
    idx = data.find(split_bytes)
    itcm_l = data[idx+4:idx+8]
    itcm_l = hex(int.from_bytes(itcm_l, byteorder='little'))
    itcm_o = data[idx+8:idx+12]
    itcm_o = hex(int.from_bytes(itcm_o, byteorder='little'))
    dtcm_l = data[idx+16:idx+20]
    dtcm_l = hex(int.from_bytes(dtcm_l, byteorder='little'))
    dtcm_o = data[idx+20:idx+24]
    dtcm_o = hex(int.from_bytes(dtcm_o, byteorder='little'))
    if idx == -1:
        print(f"Split value {split_hex} not found in file.")
        sys.exit(4)
    print(f"ITCM length {itcm_l}")
    print(f"ITCM offset {itcm_o}")
    print(f"DTCM length {dtcm_l}")
    print(f"DTCM offset {dtcm_o}")

def main():
    if len(sys.argv) != 2:
        print("Usage: python3 memorymap.py <input_file>")
        sys.exit(1)
    input_file = sys.argv[1]
    output_file = "output.bin"
    trimmed_file = "trimmed_output.bin"
    run_srec_cat(input_file, output_file)
    trim_zeros(output_file, trimmed_file)
    split_file_on_magic(trimmed_file, "00800D40")

if __name__ == "__main__":
    main()