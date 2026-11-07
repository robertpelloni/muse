#!/usr/bin/env python3
"""
Unit test suite for muse-find-unused-wavs utility.
Tests CLI argument handling, dry-run scanning, and moving unused files.
"""
import unittest
import subprocess
import os
import tempfile
import sys

SCRIPT_PATH = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "..", "src", "utils", "muse-find-unused-wavs")
)

class TestFindUnusedWavs(unittest.TestCase):

    def test_help_flag(self):
        """Verify that --help exits cleanly with return code 0."""
        res = subprocess.run([sys.executable, SCRIPT_PATH, "--help"],
                             stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.assertEqual(res.returncode, 0)
        self.assertIn("Check WAV file usage across MusE song files", res.stdout)

    def test_dry_run_detection(self):
        """Verify that --dry-run detects unused files without moving them."""
        with tempfile.TemporaryDirectory() as tmpdir:
            # Create a used wav and an unused wav
            used_wav = os.path.join(tmpdir, "used.wav")
            unused_wav = os.path.join(tmpdir, "unused_track.wav")
            open(used_wav, "w").close()
            open(unused_wav, "w").close()

            # Create a .med file referencing used.wav
            med_file = os.path.join(tmpdir, "song.med")
            with open(med_file, "w") as f:
                f.write("<muse version=\"2.0\">\n<wavefile name=\"used.wav\"/>\n</muse>")

            res = subprocess.run([sys.executable, SCRIPT_PATH, "-d", tmpdir, "--dry-run"],
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            self.assertEqual(res.returncode, 0)
            self.assertIn("unused_track.wav", res.stdout)
            self.assertIn("Dry-run mode: No files moved.", res.stdout)

            # Confirm unused_track.wav is still in the original directory
            self.assertTrue(os.path.exists(unused_wav))
            self.assertFalse(os.path.exists(os.path.join(tmpdir, "unused")))

    def test_non_interactive_move(self):
        """Verify that --yes moves unused files to the 'unused' subdirectory."""
        with tempfile.TemporaryDirectory() as tmpdir:
            used_wav = os.path.join(tmpdir, "used.wav")
            unused_wav = os.path.join(tmpdir, "unused_track.wav")
            open(used_wav, "w").close()
            open(unused_wav, "w").close()

            med_file = os.path.join(tmpdir, "song.med")
            with open(med_file, "w") as f:
                f.write("<muse version=\"2.0\">\n<wavefile name=\"used.wav\"/>\n</muse>")

            res = subprocess.run([sys.executable, SCRIPT_PATH, "-d", tmpdir, "-y"],
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            self.assertEqual(res.returncode, 0)
            self.assertIn("Completed cleanly.", res.stdout)

            # Confirm unused_track.wav has moved to 'unused' subfolder
            self.assertFalse(os.path.exists(unused_wav))
            self.assertTrue(os.path.exists(os.path.join(tmpdir, "unused", "unused_track.wav")))
            # Confirm used_wav is untouched
            self.assertTrue(os.path.exists(used_wav))

if __name__ == "__main__":
    unittest.main()
