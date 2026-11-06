#!/usr/bin/env python3
"""
Regression test suite for MusE song conversion utility.
Verifies CLI behavior, legacy XML format parsing, and conversion outputs.
"""
import unittest
import subprocess
import os
import tempfile
import sys

SCRIPT_PATH = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "..", "src", "utils", "muse-song-convert.py")
)

class TestMusESongConvert(unittest.TestCase):

    def test_help_flag(self):
        """Verify that --help exits with code 0 and displays usage information."""
        res = subprocess.run([sys.executable, SCRIPT_PATH, "--help"],
                             stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.assertEqual(res.returncode, 0)
        self.assertIn("Usage: muse-convert", res.stdout)

    def test_nonexistent_file(self):
        """Verify that nonexistent file exits with code 1 and error message."""
        res = subprocess.run([sys.executable, SCRIPT_PATH, "/path/does/not/exist.med"],
                             stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.assertEqual(res.returncode, 1)
        self.assertIn("does not exist", res.stdout)

    def test_conversion_flow(self):
        """Verify converting a mock legacy 1.0 song file."""
        legacy_content = (
            "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            "<muse version=\"1.0\">\n"
            "  <song>\n"
            "    <track name=\"Midi 1\" type=\"1\">\n"
            "    </track>\n"
            "  </song>\n"
            "</muse>\n"
        )
        with tempfile.TemporaryDirectory() as tmpdir:
            test_file = os.path.join(tmpdir, "test_song.med")
            with open(test_file, "w") as f:
                f.write(legacy_content)

            res = subprocess.run([sys.executable, SCRIPT_PATH, test_file],
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            self.assertEqual(res.returncode, 0)
            self.assertIn("Processing file", res.stdout)

            converted_file = test_file + ".converted"
            self.assertTrue(os.path.exists(converted_file))
            with open(converted_file, "r") as f:
                converted_content = f.read()

            self.assertIn("<muse version=\"2.0\"", converted_content)

if __name__ == "__main__":
    unittest.main()
