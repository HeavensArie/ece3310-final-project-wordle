# ECE 3310 Final Project

**Project members:** Donna La, Kenneth Lee, Emerson Piedad

This is the final project for ECE 3310.

## Helpful Notes

### New Concepts
- **`auto`:** Tells the compiler to get its variable type from right hand side.

### GitHub Workflow if using command line

1. Start from the latest `main` branch and create a branch for the new functionality:

   ```bash
   git switch main
   git pull
   git switch -c my-feature
   ```

2. Work on the branch until you have a meaningful change. Check which files have changed:

   ```bash
   git status
   ```

3. Stage the files you want included in the commit:

   ```bash
   git add filename
   ```

4. Commit the staged changes with a helpful message:

   ```bash
   git commit -m "Describe the change"
   ```

5. Push the branch to GitHub. Replace `my-feature` with your branch name:

   ```bash
   git push -u origin my-feature
   ```

   The `-u` option sets the upstream for the first push. After that, you can use `git push` on that branch.