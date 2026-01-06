# Contributing Guide (CONTRIBUTING.md)

## Branching Strategy
We use a GitFlow-like workflow:

- `main`: stable releases (Week 4 final merge happens here)
- `develop`: integration branch for ongoing work
- `feature/*`: new work branches created from `develop`
- `fix/*`: hotfix branches created from `develop` when needed

**Rule:** Do not push directly to `main` or `develop`. Use Pull Requests.

---

## Issue Workflow (Required)
1) Create/assign an issue for the task
2) Create a branch from `develop` (feature/* or fix/*)
3) Commit changes (small, meaningful commits)
4) Open a Pull Request into `develop`
5) Get at least **1 approving review**
6) Merge PR → close issue → update Project board

---

## Pull Request Rules
- PR target branch: **develop**
- Keep PRs small and focused
- CI (GitHub Actions) must be green
- At least 1 approving review is required

---

## Commit Message Style
Use short and descriptive messages, examples:
- `docs: expand MANUAL with full usage guide`
- `docs: finalize INSTALL for Week 4`
- `chore: update README documentation links`
- `test: add integration test notes`

---

## Week 4 Final Merge & Release Process (Important)
**We merge to `main` only at the end of Week 4.**

Final steps:
1) Ensure all Week 4 PRs are merged into `develop`
2) Confirm GitHub Actions checks are green on `develop`
3) Open a PR: `develop` → `main`
4) Get at least 1 approval and merge
5) Create a release tag (GitHub UI):
   - Releases → “Draft a new release”
   - Tag: `v1.0.0` (or course-required version)
   - Target: `main`
   - Title: “Week 4 Final Release”
   - Describe what is delivered
6) Confirm Docker Hub final images/tags are updated and documented

---

## Documentation Requirements (Week 4)
- `README.md` must include Docker Hub image links
- `INSTALL.md` must explain setup and docker compose run
- `MANUAL.md` must explain how to run and use the application
- Code should be sufficiently commented
- Wiki pages must be completed (meeting notes, decision log, progress report, final checklist)
