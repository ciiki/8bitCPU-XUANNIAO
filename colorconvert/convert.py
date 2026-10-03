from PIL import Image

palette_img = Image.open("colortable.png").convert("RGB")
source_img = Image.open("ciiki.png").convert("RGB")

if source_img.size != (64, 64):
    raise ValueError(f"ciiki.png 尺寸为 {source_img.size}，不是 64x64")

# 提取 ct.png 的调色板颜色
palette = list(dict.fromkeys(palette_img.getdata()))

if len(palette) > 256:
    raise ValueError(f"调色板颜色超过 256 种：{len(palette)}")

# 补足到 256 色
palette += [(0, 0, 0)] * (256 - len(palette))

# 创建自定义调色板
palette_image = Image.new("P", (1, 1))

flat_palette = []
for r, g, b in palette:
    flat_palette.extend([r, g, b])

palette_image.putpalette(flat_palette)

# 映射到自定义调色板
mapped = source_img.quantize(
    palette=palette_image,
    dither=Image.Dither.NONE
)

# 获取 4096 个 8-bit 调色板索引
pixels = list(mapped.getdata())

if len(pixels) != 4096:
    raise ValueError(f"像素数量不是 4096，而是 {len(pixels)}")

# 直接写入二进制文件
with open("pic.bin", "wb") as f:
    f.write(bytes(pixels))

print("已生成 pic.bin")
print("文件大小：", len(pixels), "字节")
