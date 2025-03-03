# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <new_filename> <destination_directory>"
    exit 1
fi

# Assign parameters to variables
NEW_NAME="$1.cpp"
DEST_DIR="$2"

# Check if the source file exists
SOURCE_FILE="main.cpp"  # Change this if the source file has a different name
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: Source file '$SOURCE_FILE' does not exist."
    exit 1
fi

# Create the destination directory if it doesn't exist
mkdir -p "$DEST_DIR"

# Copy and rename the file
cp "$SOURCE_FILE" "$DEST_DIR/$NEW_NAME"

# Check if the operation was successful
if [ $? -eq 0 ]; then
    echo "Saved problem #$1 to $DEST_DIR"
else
    echo "Error copying file."
    exit 1
fi